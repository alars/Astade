//declare the macros for the port concept
#define DECLARE_OUTPUT_PORT(port) ACF_MessageReceiver* port;
#define DECLARE_INPUT_PORT(port) void* port;
#define DECLARE_OUTPUT_DELEGATE(port) ACF_MessageReceiver** port;
#define DECLARE_INPUT_DELEGATE(port) void** port;