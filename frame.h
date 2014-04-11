#ifndef FRAME_H
#define FRAME_H

typedef struct frame {
	int column;		// this is the index into the user's input list.
//	Memo  memo;		// consider making this an index into a table.
	struct frame*  caller; // does this link across the tree?
	struct frame* parseTree; // if there is no subtree, then this is null.
	Token ic; // a integer representing the location in grammar table where you currently are.
	struct frame*  qLink;
} Frame;

#endif
