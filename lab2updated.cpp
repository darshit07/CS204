#include<bits/stdc++.h>
using namespace std;
struct node{
	int data_1;
	int data_2;
	struct node* forward;
};
struct node* top = NULL;
int addFirst(int data_1, int data_2){
	struct node* b = NULL;
	b = new node();
	b->data_1 = data_1;
	b->data_2 = data_2;
	b->forward=NULL;
	if(top == NULL){
    top = b;
    return 0;
	}
	else{
    b->forward = top;
    top = b;
return 0;
	}
}

int DelFirst(){
	struct node* b=top;
	if(top == NULL){
    cout<<"-1\n";
    return -1;
	}
	else{
    top = top->forward;
    delete b;
    return 0;
	}
}

int Del(int data_1, int data_2){
	struct node* b = top;
	struct node* temp = NULL;
	if(b->data_1 && b->data_2 == data_2){
    top = top->forward;
    delete b;
    return 0;
	}
	while((b->data_1 != data_1 || b->data_2 != data_2) && b->forward != NULL){
    temp = b;
    b= b->forward;
	}
	if(b->data_1 == data_1 && b->data_2 == data_2){
    temp->forward = b->forward;
    delete b;
	}
	else{
		return -1;
	}
	return 0;
}
int Length(){
	int z =0 ;
	struct node* ptr = top;
	while(ptr != NULL){
    z++;
    ptr=ptr->forward;
	}
	return z;
}
bool Search(int data_1, int data_2){
	struct node* ptr = top;
	while(ptr != NULL){
    if(ptr->data_1 == data_1 && ptr->data_2 ==data_2){
    return 1;
		}
    ptr=ptr->forward;
	}
	return 0;
}
int Search(float d){
    int aa = 0;
	struct node* ptr = top;
	while(ptr != NULL){
    int data_2 = ptr->data_1;
    int z = ptr->data_2;
    if(data_2*data_2+z*z <= d*d){
			aa++;
		}
		ptr=ptr->forward;
	}
	if(aa == 0){aa = -1;}
	return aa;
}
int main(){
	long long t;
	cin>>t;
	while(t--){
    long long data_1;
    cin>>data_1;
    if(data_1 == 1){
    int data_2, z;
    cin>>data_2>>z;
    addFirst(data_2, z);
    }
    else if(data_1==2){
            //int k=
    DelFirst();
			//if(k){
             //   cout<<k<<endl;
			//}
		}
    else if(data_1 == 3){
    int data_2, z;
    cin>>data_2>>z;
    int k = Del(data_2, z);
    if(k){cout<<k<<endl;}
		}
    else if(data_1 == 4){
    float d;
    cin>>d;
    int k=Search(d);
    cout<<k<<endl;
		}
    else if(data_1 == 5){
    int data_2, z;
    cin>>data_2>>z;
    if(Search(data_2, z)){
    cout<<"1\n";
    }else{
    cout<<"0\n";
        }
		}
		else if(data_1==6){
        cout<<Length()<<endl;
		}
	}
}
