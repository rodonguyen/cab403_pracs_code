//#include
extern void panic (void);
extern void func1 (uint32_t a);
extern uint32_t failure;

void func1 (uint32_t  a) {
	uint32_t path = 0; //default path C:\Test\
	if (failure) {
		panic();
	}
}
