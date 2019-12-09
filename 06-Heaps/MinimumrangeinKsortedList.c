#define LISTS 10

int heap_size=3; // the size of the heap is k initially
int N=5;

#define INT_MAX  100000
#define INT_MIN  -100000

struct MinHeapNode
{
    int element; // The element to be stored
    int i; // index of the list from which the element is taken
    int j; // index of the next element to be picked from list
};

struct MinHeapNode MinHeap[LISTS];

// to get index of left child of node at index i
int left(int i) { return (2*i + 1); }

// to get index of right child of node at index i
int right(int i) { return (2*i + 2); }


buildMinHeap(struct MinHeapNode *harr, int size)
{
    int i = (size - 1)/2;
    while (i >= 0)
    {
        minHeapify(harr,i);
        i--;
    }
}

minHeapify(struct MinHeapNode *harr, int i)
{

    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size &&
        harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size &&
        harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        minHeapify(harr,smallest);
    }
}

swap(struct MinHeapNode  * a, struct MinHeapNode * b)
{
    int temp;



    temp = a->element;
    a->element = b->element;
    b->element = temp;

    temp = a->i;
    a->i = b->i;
    b->i = temp;

    temp = a->j;
    a->j = b->j;
    b->j = temp;
}

struct minHeapnode * extractMin (int harr[], int *size)
{
  if (*size <= 0)
    return -1;
  if (*size == 1)
    {
      (*size)--;
      return harr[0];
    }

  // Store the minimum value, and remove it from heap
  int root = harr[0];
  harr[0] = harr[(*size) - 1];
  (*size)--;
  minHeapify (harr, 0);

  return root;

}


findSmallestRange(int arr[][N],int k)
{
    int min= INT_MAX, max=INT_MIN, range = INT_MAX, start, end;
    for(int i=0; i<k; i++)
    {
        MinHeap[i].element = arr[i][0];
        MinHeap[i].i = i;
        MinHeap[i].j = 1;
        if (MinHeap[i].element > max)
            max = MinHeap[i].element;
    }


    buildMinHeap(MinHeap, heap_size);
   /* for(int i =0; i < heap_size; i++)
    {
        printf(" %d",(MinHeap[i]).element);
    }*/
    struct MinHeapNode * root;

    while(1)
    {
        root = (struct MinHeapNode *) malloc(sizeof(struct MinHeapNode));
        //copying the min of the heap into the root structure
        root->element = MinHeap[0].element;
        root->i = MinHeap[0].i;
        root->j = MinHeap[0].j;
        // updating min
        min = root->element;
        //updation
        if(range > max - min +1)
        {
            range = max - min +1;
            start = min;
            end = max;
        }

        //delete the min and insert the next element from the same list
        // to which the deleted min belongs to. Instead of using the delete
        // min and insert, we do replace the root of the heap and call
        //heapify
        if((root->j)<N)//check if the list contains more elements
        {
            root->element = arr[root->i][root->j];
            (root->j) += 1;
            //update max
            if((root->element) > max )
             max = root->element;
        }
        else break;


        replaceMinAndHeapify(root);

    }

    printf("the range is %d and %d",start,end);

}

replaceMinAndHeapify(struct MinHeapNode *root)
{
    MinHeap[0].element = root->element;
    MinHeap[0].i = root->i;
    MinHeap[0].j = root->j;

    minHeapify(MinHeap,0);
    //printf("\n");
   /* for(int i =0; i < heap_size; i++)
    {
        printf(" %d",(MinHeap[i]).element);
    }*/

}

int main()
{
    int arr[][5] = {
                    {4, 7, 9, 12, 15},
                    {0, 8, 10, 14, 20},
                    {6, 12, 16, 30, 50}
                    };
    int k = sizeof(arr)/sizeof(arr[0]);

    findSmallestRange(arr, k);

    return 0;
}
