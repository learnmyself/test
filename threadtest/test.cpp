#include<iostream>
#include<pthread.h>

using namespace std;

void* thread(void*)
{
	for(int i = 0; i < 5; i++)
		cout<<"this is " <<i<< "thread!"<<endl;
}

void* thread2(void*)
{
	for(int i = 0; i <5; i++)
		cout<<"the second "<<i <<"thread!"<<endl;
}

int main()
{
	pthread_t id, id2;
	pthread_attr_t attr, attr2;
	pthread_attr_init(&attr);
	pthread_attr_init(&attr2);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);
	pthread_attr_setscope(&attr2, PTHREAD_SCOPE_PROCESS);
	sched_param param;
	pthread_attr_getschedparam(&attr, &param);
	param.sched_priority=20;
	pthread_attr_setschedparam(&attr, &param);
	
	pthread_attr_getschedparam(&attr2, &param);
	param.sched_priority = 10;
	pthread_attr_setschedparam(&attr2, &param);

	int ret = pthread_create(&id, &attr, &thread, NULL);
		ret = pthread_create(&id2, &attr2, &thread2, NULL);
	
	cout<<"thread id is"<<id<<endl;
	if(ret != 0) {
		cout<<"create pthread error!"<<endl;
	}
	for(int i = 0; i< 5; i++)
		cout<<"This is "<<i<<"main process!!!"<<endl;

	pthread_join(id, NULL);
	pthread_join(id2, NULL);
	return 0;
}
