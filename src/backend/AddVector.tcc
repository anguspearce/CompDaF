#ifndef ADDVECTOR_TCC
#define ADDVECTOR_TCC

template <typename T, typename F>
AddVector<T, F>::AddVector(F &max, F &min) : raft::kernel(), min(min), max(max)
{

    input.addPort<T>("addvec");
    output.addPort<std::vector<F>>("total");
}

template <typename T, typename F>
AddVector<T, F>::AddVector(const AddVector &other) : raft::kernel(), min(other.min), max(other.max)
{

    input.addPort<T>("addvec");
    output.addPort<std::vector<F>>("total");
}

template <typename T, typename F>
raft::kstatus AddVector<T, F>::run()
{
    //T t;

    //input["addvec"].template pop(t);
    auto &t(input["addvec"].template peek<T>());
    F addVecTot = 0;
    std::vector<F> totals={0,0};
    for (int i = 0; i < t.size(); i++)
    {
        for (int j = 0; j < t[i].first.size(); j++)
        {
            //std::cout<<"test"<<std::endl;
            if (t[i].first[j] < min)
            {
                min = t[i].first[j];
            }

            if (t[i].first[j] > max)
            {
                max = t[i].first[j];
            }
            totals[0] += t[i].first[j];
            totals[1]+= (t[i].first[j]*t[i].first[j]);
        }
    }
    input["addvec"].unpeek();

    auto c(output["total"].template allocate_s<std::vector<F>>());
    (*c) = totals;

    output["total"].send();
    input["addvec"].recycle(1);

    return (raft::proceed);
}

#endif