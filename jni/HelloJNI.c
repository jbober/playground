#include <jni.h>
#include <stdio.h>
#include "HelloJNI.h"
#include <iostream>
#include <unistd.h>
#include <sstream>

int gdb_process_pid = 0;
using namespace std;

void exec_gdb()
{
    // Create child process for running GDB debugger
    int pid = fork();
    
    if (pid < 0) /* error */
    {
        abort();
    }
    else if (pid) /* parent */
    {
		// Application process

        gdb_process_pid = pid; // save debugger pid
        sleep(10); /* Give GDB time to attach */

		// Continue the application execution controlled by GDB
    }
    else /* child */
    {
		// GDB process. We run DDD GUI wrapper around GDB debugger

        stringstream args;
		// Pass parent process id to the debugger
        args << "--pid=" << getppid();
        
		// Invoke DDD debugger
        execl("ddd", "ddd", "--debugger", "gdb", args.str().c_str(), (char *) 0);
        
		// Get here only in case of DDD invocation failure
        cerr << "\nFailed to exec GDB (DDD)\n" << endl;
    }
}
 
// Implementation of native method sayHello() of HelloJNI class
JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
exec_gdb(); // this does not work 
   printf("Hello World!\n");
   return;
}
