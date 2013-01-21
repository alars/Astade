//~~ void notify_function_call(char* objectName, char* functionName, void* objectID) [trace2uml_driver] ~~
static DEFINE_SPINLOCK(xxx_lock);
unsigned long flags;

spin_lock_irqsave(&xxx_lock, flags);

trace2uml_driver_buffer[trace2uml_driver_nextWrite].type = FUNCTIONCALL;
trace2uml_driver_buffer[trace2uml_driver_nextWrite].calledFunction = functionName;
trace2uml_driver_buffer[trace2uml_driver_nextWrite].calledID = objectID;
trace2uml_driver_buffer[trace2uml_driver_nextWrite].threadID = 0;
trace2uml_driver_buffer[trace2uml_driver_nextWrite++].calledName = objectName;

if (trace2uml_driver_nextWrite >= RINGSIZE)
    trace2uml_driver_nextWrite = 0;

spin_unlock_irqrestore(&xxx_lock, flags);