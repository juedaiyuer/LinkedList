#include<iostream.h>

typedef struct node
{
	int val;
	struct node* pNext;
} NODE,*PNODE;

class MyList{
	private:
		PNODE pHead;
	public:
		MyList(){
			this ->pHead = NULL;
		}
		~MyList(){
			while(this ->pHead != NULL){
				PNODE pTemp = pHead->pNext;
				delete pHead;
				pHead = pTemp;
			}
		}
		void Init()   //List Initialization 
		{
			int a;
			char ans;  //provie end loop of do-while;
			PNODE pTail,pNew;
			do{
				cout<<"please input int x:";
				cin>>a;
				if(pHead == NULL)
				{
					pHead = new NODE;
					pHead->val=a;
					pHead->pNext = NULL;
					pTail = pHead;
				}else{
					pTail = pHead;
					while(pTail->pNext != NULL)
					{
						pTail = pTail->pNext;
					}

					pNew = new NODE;
					pNew->val = a;
					pNew->pNext = NULL;

					pTail->pNext = pNew;
					pTail=pTail->pNext;
				}
				cout<<"continue?(Y/N): ";
				cin>>ans;
			}while(ans=='Y'||ans=='y');
		}

		void Add(int val){
			if(pHead == NULL)
			{
				pHead = new NODE;
				pHead ->val = val;
				pHead ->pNext = NULL;
			}else
			{
				PNODE pTemp = pHead;
				while(pTemp->pNext != NULL)
				{
					pTemp = pTemp->pNext;
				}

				PNODE pNew = new NODE;
				pNew->val = val;
				pNew->pNext=NULL;

				pTemp->pNext = pNew;
			}

		}

		void DelAt(int k)   
		{
			PNODE p1,p2;				
			for(p2=NULL,p1=pHead;p1;p2=p1,p1=p1->pNext)
			{
				if(p1->val == k)
					if(p2){
						p2->pNext = p1->pNext;
					}else{
						pHead = p1->pNext;
					}
					delete(p1);
			}

		}												

		void Travel()  // print list 
		{
				PNODE pTemp = this->pHead;
				while(pTemp != NULL)
				{
					cout<<pTemp->val<<" ";
					pTemp = pTemp->pNext;
				}
				cout<<endl;

		}

		int GetNodeCnt()
		{
			int cnt = 0;
			PNODE pTemp = pHead;
			while(pTemp != NULL)
			{
				cnt++;
				pTemp = pTemp->pNext;
			}
			return cnt;
		}

		void sort()  // 1.from big to small  2.this method of sort ignore complexity,only traversal.

		{
			int n = this->GetNodeCnt();
			PNODE p1,p2;
			for(int i=0;i<n-1;i++)
			{
				p1 = pHead;
				for(int j=1;j<n-1-i;j++)
				{
					p2 = p1->pNext;
					if(p1->val<p2->val)
					{
						int k = p1->val;
						p1->val = p2->val;
						p2->val = k;
					}
					p1 = p1->pNext;
				}
			}
		}


};
void main()
{
	MyList list;
	for(int i=0;i<10;i++)
	{
		list.Add(i);
	

	}
	list.Travel();
	cout<<list.GetNodeCnt()<<endl;

	list.Init();
	list.Travel();
	cout<<list.GetNodeCnt()<<endl;

	list.DelAt(2);
    list.Travel();

//	list.sort();
//	list.Travel();

}