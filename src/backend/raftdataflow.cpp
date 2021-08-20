#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

template <typename T>
class SplitVector : public raft::parallel_k
{
public:
    //T total = 0;
    SplitVector() : raft::parallel_k()
    {
        /** define ports **/
        input.addPort<T>("a");
        output.addPort<std::vector<std::pair<T, raft::signal>>>("split");
    }

    virtual raft::kstatus run()
    {
        //T a;
        /** ports are accessed via names defined above **/
        //auto &val(input["input_a"].template peek<T>());
        //std::cout << "peek: " << val << std::endl;
        std::vector<std::pair<T, raft::signal>> r(2);
        std::vector<std::pair<T, raft::signal>> &t = r;
        input["a"].template pop_range(t, 2);

        //input["input_b"].pop(b);
        /** allocate mem directly on queue **/
        auto c(output["split"].template allocate_s<std::vector<std::pair<T, raft::signal>>>());
        (*c) = t;

        //std::cout << "total vec = " << counter << std::endl;
        //std::cout << "peek: " << val << std::endl;

        //total += val;
        /** 
       * mem for C pushed to queue on scope exit, proceed 
       * signals the run-time to continue 
       */
        return (raft::proceed);
    }
};

template <typename T>
class AddVector : public raft::parallel_k
{
public:
    double addVecTot;
    AddVector() : raft::parallel_k()
    {
        addVecTot = 0;

        /** define ports **/
        input.addPort<T>("addvec");
        //output.addPort<T>("total");
    }

    virtual raft::kstatus run()
    {
        T t;
        /** ports are accessed via names defined above **/
        //auto &val(input["input_a"].template peek<T>());
        //std::cout << "peek: " << val << std::endl;
        // std::vector<std::pair<T, raft::signal>> r(2);
        // std::vector<std::pair<T, raft::signal>> &t = r;
        input["addvec"].template pop(t);
        for (int i = 0; i < t.size(); i++)
        {
            for(int j=0; j<t[i].first.size();j++){
                addVecTot += t[i].first[j];
            }
            //std::cout<<t[i].first.size()<<std::endl;
            // addVecTot += t[i][j].first;
        }

        //input["input_b"].pop(b);
        /** allocate mem directly on queue **/
        // auto c(output["sum"].template allocate_s<std::vector<std::pair<T, raft::signal>>>());
        //(*c) = t;

        //std::cout << "total vec = " << counter << std::endl;
        //std::cout << "peek: " << val << std::endl;

        //total += val;
        /** 
       * mem for C pushed to queue on scope exit, proceed 
       * signals the run-time to continue 
       */
        return (raft::proceed);
    }
};

int main()
{
    using type_v = std::vector<double>;
    using type_a = std::vector<std::pair<type_v, raft::signal>>;
    using splitvec = SplitVector<type_v>;
    using addvec = AddVector<type_a>;
    splitvec sp;
    addvec av;
    raft::map m;

    //Creating dummy vectors of vectors
    using ex_t = double;
    /** data source & receiver container **/
    std::vector<type_v> o;
    int j = 0;
    while (j < 12200)
    {
        type_v v;

        ex_t i(0);
        /** fill container **/
        // auto func([&]()
        //           { return (i++); });
        while (i < 8700)
        {
            v.emplace_back(1);
            i++;
        }
        o.push_back(v);
        j++;
    }

    //loading each vector into a kernel
    auto readeachone(raft::read_each<type_v>(o.begin(), o.end()));
    m += readeachone >> sp>>av;
    m.exe();
    std::cout<<"Raft Sum: "<<av.addVecTot<<std::endl;

    //fake time
    double fakeval=0;
    std::vector<type_v> gg;
    int jj = 0;
    while (jj < 12200)
    {
        type_v gv;

        ex_t ii(0);
        /** fill container **/
        // auto func([&]()
        //           { return (i++); });
        while (ii < 8700)
        {
            gv.emplace_back(1);
            ii++;
        }
        gg.push_back(gv);
        jj++;
    }
    for( int k=0;k<o.size();k++){
        for(int l=0;l<o[k].size();l++){
            fakeval+=o[k][l];
        }
    }
    std::cout<<"Regular Sum: "<<fakeval<<std::endl;


    return 0;
}