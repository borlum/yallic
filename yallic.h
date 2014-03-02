#define ID_LENGHT_MAX 80

struct yallicNode {
   char id[ID_LENGHT_MAX+1];
   void *data;
   struct yallicNode *next;
};

typedef struct yallicNode *yallicList;

yallicList createList();