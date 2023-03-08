class Heap{
	vector<int>v;
	int size;
public:
	Heap(){
		size=0;
		v.push_back(-1);
	}
	// Using 1-Based Indexing
	void insert_into_heap(int x){
		size++;
		v.push_back(x);
		int idx=size;
		while(idx>1){
			int par_idx=idx/2;
			if(v[par_idx]<v[idx]){
				swap(v[par_idx],v[idx]);
				idx=par_idx;
			}else {
				return;
			}
		}
	}
	void print_heap(){
		cout<<"Number of elements in Heap currently: "<<size<<endl;
		for(int i=1;i<=size;i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
	void delete_from_heap(){
		// deleting from heap means deleting the root of the CBT (Complete Binary tree)
        // i.e the heap
		if(size==0){
			return;
		}
		swap(v[size],v[1]);
		size--;
		int idx=1;
		while(1){
			int left_idx=2*idx,right_idx=2*idx+1;
			if(left_idx<=size&&v[idx]<v[left_idx]&&(right_idx>size||v[right_idx]<=v[left_idx])){
				swap(v[idx],v[left_idx]);
				idx=left_idx;
			}else if(right_idx<=size&&v[right_idx]>v[idx]){
				swap(v[idx],v[right_idx]);
				idx=right_idx;
			}else {
				return;
			}
		}
	}
	void delete_from_heap_less_code(){
		// deleting from heap means deleting the root of the CBT (Complete Binary tree)
        // i.e the heap
		if(size==0){
			return;
		}
		swap(v[size],v[1]);
		size--;
		int idx=1;
		while(1){
			int left_idx=2*idx,right_idx=2*idx+1,largest=idx;

			if(left_idx<=size&&v[largest]<v[left_idx])largest=left_idx;

			if(right_idx<=size&&v[largest]<v[right_idx])largest=right_idx;

			if(largest==idx){
        		// node value is bigger than both it's children's values
				return;
			}else {
				swap(v[idx],v[largest]);
				idx=largest;
			}
		}
	}
};

//DO NOT run this function for range idx=[n/2+1,n]

//total complexity will be O(n) and NOT O(nlogn)

//https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity

void heapify(vector<int>& v,int n,int idx){
	int largest=idx,left_idx=2*idx,right_idx=2*idx+1;

	if(left_idx<=n&&v[largest]<v[left_idx])largest=left_idx;

	if(right_idx<=n&&v[largest]<v[right_idx])largest=right_idx;

//debug(idx,largest);

	if(largest!=idx){
		swap(v[largest],v[idx]);
		heapify(v,n,largest);
	}
}


// given a vector, we have to sort the vector/array in O(nlogn)
void heap_sort(vector<int>& v,int n){
	int size=n;
	while(size>1){
		swap(v[1],v[size]);
		size--;
		heapify(v,size,1);
	}
}	
