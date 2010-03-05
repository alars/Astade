ACF_traceTimestamp();
ACF_tracePtr(pMessageReceiver);
ACF_trace(((ACF_MessageReceiver*)pMessageReceiver)->Name);
ACF_trace(" >>> ");
ACF_trace(state);
ACF_trace("\n");
