//declare the macros for the port concept
#define DECLARE_OUTPUT_PORT(port) ACF_MessageReceiver* port; ACF_MessageReceiver** port##_delegate;
#define DECLARE_INPUT_PORT(port) void* port; void** port##_delegate;
#define DECLARE_OUTPUT_DELEGATE(port) ACF_MessageReceiver** port##_delegate;
#define DECLARE_INPUT_DELEGATE(port) void** port##_delegate;

#define INITIALIZE_OUTPUT_PORT(port) port##_delegate = &port;
#define INITIALIZE_INPUT_PORT(port) port##_delegate = &port;
#define INITIALIZE_INPUT_DELEGATE(port, object, oport) port##_delegate = object.oport##_delegate;
#define INITIALIZE_OUTPUT_DELEGATE(port, object, oport) port##_delegate = object.oport##_delegate;

#define CONNECT_INPUT_TO_OUTPUT(inObject, inPort, outObject, outPort) *outObject.outPort##_delegate = &inObject; *inObject.inPort##_delegate = &outObject;