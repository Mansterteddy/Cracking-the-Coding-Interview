//非递归实现中序遍历

#include <iostream>

using namespace std;

void pre_order_1(Node *root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		pre_order_1(root->lchild);
		pre_order_1(root->rchild);
	}
}

void pre_order_2(Node *root)
{
	stack<Node*> s;
	Node *p = root;
	while(p != NULL || !s.empty())
	{
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			s.push(p);
			p = p->lchild;
		}
		if(!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}

void in_order_1(Node *root)
{
	if(root != NULL)
	{
		in_order_1(root->lchild);
		cout<<root->data<<" ";
		in_order_1(root->rchild);
	}
}

void in_order_2(Node *root)
{
	stack<Node*> s;
	Node* p = root;

	while(p != NULL || !s.empty())
	{
		while(p != NULL)
		{
			s.push(p);
			p = p ->lchild;
		}
		if(!s.empty())
		{
			p = s.top();
			cout<<p->data<<" ";
			s.pop();
			p = p->rchild;
		}
	}

}

void post_order_1(Node *root)
{
	if(root != NULL)
	{
		post_order_1(root->lchild);
		post_order_1(root->rchild);
		cout<<root->data<<" ";
	}
}

void postOrder2(BinTree *root)    //非递归后序遍历
{
    stack<BTNode*> s;
    BinTree *p=root;
    BTNode *temp;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)              //沿左子树一直往下搜索，直至出现没有左子树的结点 
        {
            BTNode *btn=(BTNode *)malloc(sizeof(BTNode));
            btn->btnode=p;
            btn->isFirst=true;
            s.push(btn);
            p=p->lchild;
        }
        if(!s.empty())
        {
            temp=s.top();
            s.pop();
            if(temp->isFirst==true)     //表示是第一次出现在栈顶 
             {
                temp->isFirst=false;
                s.push(temp);
                p=temp->btnode->rchild;    
            }
            else                        //第二次出现在栈顶 
             {
                cout<<temp->btnode->data<<" ";
                p=NULL;
            }
        }
    }    
} 