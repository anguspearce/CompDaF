import dlg

##
# @brief SleepApp\n
# @details An APP to play around with 
# @par EAGLE_START
# @param gitrepo $(GIT_REPO)
# @param version $(PROJECT_VERSION)
# @param category PythonApp
# @param[in] param/sleepTime/5/Integer/readwrite
#     \~English the number of seconds to sleep\n
# @param[in] param/appclass/dlg.apps.simple.SleepApp/String/readonly
#     \~English Application class\n

# @par EAGLE_END
class Daliuge(dlg.drop.BarrierAppDROP):
    def __init__(self):
        print("Init")

    def run():
        #Application Logic
        print("Define logic")
        super().addConsumer()

##
# @brief SleepApp\n
# @details A simple APP that sleeps the specified amount of time (0 by default).
# This is mainly useful (and used) to test graph translation and structure
# without executing real algorithms. Very useful for debugging.
# @par EAGLE_START
# @param gitrepo $(GIT_REPO)
# @param version $(PROJECT_VERSION)
# @param category PythonApp
# @param[in] param/sleepTime/5/Integer/readwrite
#     \~English the number of seconds to sleep\n
# @param[in] param/appclass/dlg.apps.simple.SleepApp/String/readonly
#     \~English Application class\n

# @par EAGLE_END
class Sum(dlg.drop.AppDROP):
    
    compontent_meta = dlg.meta.dlg_component('RandomArrayApp', 'Random Array App.',
                                    [dlg.meta.dlg_batch_input('binary/*', [])],
                                    [dlg.meta.dlg_batch_output('binary/*', [])],
                                    [dlg.meta.dlg_streaming_input('binary/*')])
    def run():
        
        
        
