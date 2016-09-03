第一种：在代码中执行系统指令
#include <stdlib.h>
int main() {
  return system("seq 1 100");
}

第二种：利用信号捕捉
#include <stdio.h>
#include <stdlib.h>
  
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
  
int i = 0;
void sig_alarm_handler(int signal) {
    ++i;
    printf("%dn", i);
    if(i < 100)
        alarm(1);
    else
        exit(0);
}
  
int main() {
    signal(SIGALRM, sig_alarm_handler);
    alarm(1);
    int x;
    scanf(" %d",&x);
    return 0;
}

第三种：利用模板参数与继承特性
#include <stdio.h>
  
template<int N>
struct X : X<N-1> {
    X() { printf("%dn", N); }
};
  
template<>
struct X<0> {};
  
int main() {
    X<100> x;
    return 0;
}


第四种：用静态变量和数组
#include <stdio.h>
  
struct X {
    static int i;
  
    X() { ++i; printf("%dn", i); }
};
  
int X::i = 0;
  
int main() {
    X arr[100];
    return 0;
}

