wxProcess::OnTerminate(pid,status); //call the base function, so the message is sent
delete this;						//delete the object, because the base function wont do that.