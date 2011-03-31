//~~ void checkMessageQueueSize() [ACF] ~~
if ((messageCount() + 3) < my_Messages.size())
    return; // messageQueue is still big enough
    
std::vector<ACF_Message> newVector;

for (unsigned int i = 0; i < (my_Messages.size() + 5); i++)
    newVector.push_back(ACF_Message());
 
unsigned int count = 0;

while (nextRead != nextWrite)
{
    newVector[count++] = my_Messages[nextRead++];
    if (nextRead >= my_Messages.size())
        nextRead = 0;
}

my_Messages = newVector;
nextRead = 0;
nextWrite = count;