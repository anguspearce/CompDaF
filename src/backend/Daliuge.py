import dlg
import pickle
import numpy as np

## 
 # \file Daliuge.py 
##
# @brief SplitVector\n
# @details An APP to play around with 
# @par EAGLE_START
# @param gitrepo $(GIT_REPO)
# @param version $(PROJECT_VERSION)
# @param category PythonApp
# @param[in] param/data/null/ndarray
#     \~English The array to split up and pass to sum\n
# @param[in] param/appclass/src.backend.Daliuge.SplitVector/String
#     \~English Application class\n
# @param[out] port/array
#     \~English Port receiving array or integer 

# @par EAGLE_END
class SplitVector(dlg.drop.BarrierAppDROP):
    def initialise(self, data):
        self.data = data

    def run(self):
        #Application Logic
        outs = 0
        arrs = np.split(self.data, 4)
        for out in self.outputs:
            out.write(arrs[outs])
            outs += 1

        

##
# @brief SumApp\n
# @details A Sum App that takes in vectors or integers and adds them all together
# @par EAGLE_START
# @param gitrepo $(GIT_REPO)
# @param version $(PROJECT_VERSION)
# @param category PythonApp
# @param[in] param/appclass/src.backend.Daliuge.Sum/String
#     \~English Application class\n
# @param[in] port/array
#     \~English Port receiving array or integer 
# @param[out] port/Integer
#     \~English Port outputs integer total

# @par EAGLE_END
class Sum(dlg.drop.AppDROP):
    
    compontent_meta = dlg.meta.dlg_component('SumApp', 'Sum App.',
                                    [dlg.meta.dlg_batch_input('binary/*', [])],
                                    [dlg.meta.dlg_batch_output('binary/*', [])],
                                    [dlg.meta.dlg_streaming_input('binary/*')])
    def run(self):
        total = 0;
        for inputDrop in self.inputs:
            if isinstance(inputDrop, dlg.drop.ContainerDROP):
                for child in inputDrop.children:
                    total += child
            else:
                total += inputDrop
        self.outputs.write(total)
        
##
# @brief SumAllApp\n
# @details SumAll App that takes in the other sum totals and adds together
# @par EAGLE_START
# @param gitrepo $(GIT_REPO)
# @param version $(PROJECT_VERSION)
# @param category PythonApp
# @param[in] param/appclass/src.backend.Daliuge.SumAll/String
#     \~English Application class\n
# @param[in] port/Integer
#     \~English Port receiving Integers to add up

# @par EAGLE_END
class SumAll(dlg.drop.AppDROP):
    
    compontent_meta = dlg.meta.dlg_component('SumAllApp', 'SumAll App.',
                                    [dlg.meta.dlg_batch_input('binary/*', [])],
                                    [dlg.meta.dlg_batch_output('binary/*', [])],
                                    [dlg.meta.dlg_streaming_input('binary/*')])
    def run(self):
        total = 0;
        for inputDrop in self.inputs:
            if isinstance(inputDrop, dlg.drop.ContainerDROP):
                for child in inputDrop.children:
                    total += child
            else:
                total += inputDrop
        print(total)
        
