#ifndef ADDVECTOR_TCC
#define ADDVECTOR_TCC

template <typename T, typename F>
AddVector<T, F>::AddVector(F &max, F &min) : raft::parallel_k(), min(min), max(max)
{

    input.addPort<T>("addvec");
    output.addPort<F>("total");
}

template <typename T, typename F>
AddVector<T, F>::AddVector(const AddVector &other) : raft::parallel_k(), min(other.min), max(other.max)
{

    input.addPort<T>("addvec");
    output.addPort<F>("total");
}

template <typename T, typename F>
raft::kstatus AddVector<T, F>::run()
{
    //T t;

    //input["addvec"].template pop(t);
    auto &t(input["addvec"].template peek<T>());
    F addVecTot = 0;
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
            addVecTot += t[i].first[j];
        }
    }
    input["addvec"].unpeek();

    auto c(output["total"].template allocate_s<F>());
    (*c) = addVecTot;

    output["total"].send();
    input["addvec"].recycle(1);

    return (raft::proceed);
}

#endif