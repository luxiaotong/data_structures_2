#include "bi_tree.h"

bi_tree create_bi_tree()
{
	bi_tree tr = (bi_tree *) malloc ( sizeof(bi_tree) );
	int i = 0;
	for ( i = 0; i < 10; i ++ ) {
		tr->element = i;
		tr->left = NULL;
	}
	return ;
}
