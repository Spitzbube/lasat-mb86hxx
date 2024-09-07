

extern Menu* menu_stack_operate(Menu*);

#define MENU_STACK_PUSH(pMenu)      menu_stack_operate(pMenu)
#define MENU_STACK_POP()           menu_stack_operate(0)

extern void menu_initialize(Menu*);

