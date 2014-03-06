#define ID_LENGHT_MAX 80

struct yallicNode {
   char id[ID_LENGHT_MAX+1];
   void *data;
   int dataSize;
   struct yallicNode *next;
};

typedef struct yallicNode *yallicList;

yallicList createList();
int appendTo(yallicList listHead, char *itemID, void *itemData, int itemDataSize);
void *findIn(yallicList listHead, char *itemID);
int deleteIn(yallicList listHead, char *itemID);
int saveList(yallicList listHead, char *fileName);
yallicList loadList(yallicList listHead, char * fileName);
yallicList destroyList(yallicList listHead);