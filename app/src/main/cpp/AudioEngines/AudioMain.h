// Loskutnikov Games 2022 .inc


class simpleTestAudio {


public:
     simpleTestAudio();

     // call from thread
     void callThread() const;
private:
       int testInteger;
};