#include<iostream>
#include<queue>
#include<array>
#include<algorithm>

using namespace std;

int* copy_arr(int* curr){
    int *ptr=new int[9];
    for(int i=0;i<9;i++){
        ptr[i]=curr[i];
    }
    return ptr;
}

void swap(int* curr,int index1,int index2){
    int temp=curr[index1];
    curr[index1]=curr[index2];
    curr[index2]=temp;
}


class State{
public:
    int emptyIndex;
    int* currState;
    int cost;
    State* parent;


    State(int* current,State* parent=NULL,int cost=0,int eIndex=-1){
        this->currState=current;   //shallow copy
        this->parent=parent;  //shallow copy.
        this->cost=cost;
        if(eIndex==-1){
            this->emptyIndex=this->getIndex(current);
        }
        else{
            this->emptyIndex=eIndex;
        }
    }


    void disp(){
        cout<<endl;
        cout<<"\nCurrent State:";
        for(int i=0;i<9;i++){
            cout<<this->currState[i]<<",";
        }

        if (this->parent != NULL)
        {
            cout << "\nParent:";
            for (int i = 0; i < 9; i++)
            {
                cout << (this->parent)->currState[i] << ",";
            }
        }
        cout<<"\nCost:"<<this->cost;
        cout<<endl;
    }

    bool operator==(State &obj){
        for(int i=0;i<9;i++){
            if(this->currState[i]!=obj.currState[i]) return false;
        }
        return true;
    }

private:

    int getIndex(int* arr){
        
        auto itr = find(arr, arr + 9, 0);
        return distance(arr,itr);
    }
};


State* left(State* curr){
    if(curr->emptyIndex==0 || curr->emptyIndex==4 || curr->emptyIndex==7){
        return NULL;
    }
    else{
        int child_eIndex=curr->emptyIndex;
        int child_cost=curr->cost+1;
        int *child_state=copy_arr(curr->currState);
        swap(child_state,child_eIndex,child_eIndex-1);
        child_eIndex-=1;
         
        State* child=new State(child_state,curr,child_cost,child_eIndex); 
    }
    
}


State* right(State* curr){
    if(curr->emptyIndex==2 || curr->emptyIndex==5 || curr->emptyIndex==8){
        return NULL;
    }
    else{
        int child_eIndex=curr->emptyIndex;
        int child_cost=curr->cost+1;
        int *child_state=copy_arr(curr->currState);
        swap(child_state,child_eIndex,child_eIndex+1);
        child_eIndex+=1;
         
        State* child=new State(child_state,curr,child_cost,child_eIndex); 
    }
    
}

State* up(State* curr){
    if(curr->emptyIndex==0 || curr->emptyIndex==1 || curr->emptyIndex==2){
        return NULL;
    }
    else{
        int child_eIndex=curr->emptyIndex;
        int child_cost=curr->cost+1;
        int *child_state=copy_arr(curr->currState);
        swap(child_state,child_eIndex,child_eIndex-3);
        child_eIndex-=3;
         
        State* child=new State(child_state,curr,child_cost,child_eIndex); 
    }
    
}


State* down(State* curr){
    if(curr->emptyIndex==7 || curr->emptyIndex==8 || curr->emptyIndex==9){
        return NULL;
    }
    else{
        int child_eIndex=curr->emptyIndex;
        int child_cost=curr->cost+1;
        int *child_state=copy_arr(curr->currState);
        swap(child_state,child_eIndex,child_eIndex+3);
        child_eIndex+=3;
         
        State* child=new State(child_state,curr,child_cost,child_eIndex); 
    }
    
}




int main(){
    int *ptr=new int[10];
    int j=8;
    for(int i=0;i<9;i++){
        ptr[i]=j--;
    }


    State* sPtr=new State(ptr);
    State* sPtr2=new State(ptr);


    return 0;
}


