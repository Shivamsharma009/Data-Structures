#include <stdio.h>

int left_heap[100];

int right_heap[100];

int left_heap_size = 0;

int right_heap_size = 0;

int parent (int i)

{

  return (i - 1) / 2;

}

   
 // to get index of left child of node at index i

int left (int i)

{
 
 return (2 * i + 1);

}

  
  // to get index of right child of node at index i

int right (int i)

{
  
return (2 * i + 2);

}


    
// Returns the minimum key (key at root) from min heap

int getMax (int harr[])

{
  
return harr[0];

}


int getMin (int harr[])

{
  
return harr[0];

}




int extractMax (int harr[], int *heap_size)

{
  
if (*heap_size <= 0)
    
return -1;
  
if (*heap_size == 1)
    
{
      
(*heap_size)--;
      
return harr[0];
    
}

  
// Store the minimum value, and remove it from heap
  
int root = harr[0];
  
harr[0] = harr[(*heap_size) - 1];
  
(*heap_size)--;
  
MaxHeapify (harr, 0, *heap_size);

  
return root;


}


int extractMin (int harr[], int *heap_size)

{
  
if (*heap_size <= 0)
    
return -1;
  
if (*heap_size == 1)
    
{
      
(*heap_size)--;
      
return harr[0];
    
}

  
// Store the minimum value, and remove it from heap
  
int root = harr[0];
  
harr[0] = harr[(*heap_size) - 1];
  
(*heap_size)--;
  
MinHeapify (harr, 0, *heap_size);

  
return root;


}



MaxHeapify (int *harr, int i, int heap_size)

{
  
int l = left (i);
  
int r = right (i);
  
int biggest = i;
  
if (l < heap_size && harr[l] > harr[i])
    
biggest = l;
  
if (r < heap_size && harr[r] > harr[biggest])
    
biggest = r;
  
if (biggest != i)
    
{
      
swap (&harr[i], &harr[biggest]);
      
MaxHeapify (harr, biggest, heap_size);
    
}


}


MinHeapify (int *harr, int i, int heap_size)

{
  
int l = left (i);
  
int r = right (i);
  
int smallest = i;
  
if (l < heap_size && harr[l] < harr[i])
    
smallest = l;
  
if (r < heap_size && harr[r] < harr[smallest])
    
smallest = r;
  
if (smallest != i)
    
{
      
swap (&harr[i], &harr[smallest]);
      
MinHeapify (harr, smallest, heap_size);
    
}


}


maxheap_insert (int harr[], int k, int *heap_size)

{
  
if (*heap_size == 100)
    
{
      
printf ("heap overflow");
      
return;
    
}

  
// First insert the new key at the end
  
(*heap_size)++;
  
int i = *heap_size - 1;
  
harr[i] = k;

  
// Fix the max heap property if it is violated
  
while (i != 0 && harr[parent (i)] < harr[i])
    
{
      
swap (&harr[i], &harr[parent (i)]);
      
i = parent (i);
    
}

}


minheap_insert (int harr[], int k, int *heap_size)

{
  
if (*heap_size == 100)
    
{
      
printf ("heap overflow");
      
return;
    
}

  
// First insert the new key at the end
  
(*heap_size)++;
  
int i = *heap_size - 1;
  
harr[i] = k;

  
// Fix the min heap property if it is violated
  
while (i != 0 && harr[parent (i)] > harr[i])
    
{
      
swap (&harr[i], &harr[parent (i)]);
      
i = parent (i);
    
}

}



void swap (int *x, int *y)

{
  
int temp = *x;

  *x = *y;
  
*y = temp;

}


int getMedian(int new_element, int old_median)

{
   
int new_median; 
   
if(left_heap_size > right_heap_size)
   
{
       
if(new_element < old_median)
        
{
         
 int left_max = extractMax (left_heap, &left_heap_size);

          minheap_insert(right_heap, left_max, &right_heap_size);
        
  maxheap_insert(left_heap, new_element, &left_heap_size);
 
         
        }
   
    else
        
{

          minheap_insert(right_heap, new_element, &right_heap_size);

          
        }
       
    new_median = (getMax(left_heap) + getMin(right_heap)) /2;
    
   return(new_median);
  
     
   }
 
  else if(left_heap_size == right_heap_size)
 
  {
      
 if(new_element < old_median)
 
      {
  
        maxheap_insert(left_heap,new_element,&left_heap_size);
  
        new_median = getMax(left_heap);
    
   }
 
      else
  
  
       {
         

         minheap_insert(right_heap,new_element,&right_heap_size);
        
 new_median = getMin(right_heap);
    
   }
   
    return(new_median);
 
  }
   
else

   {
  
     if(new_element < old_median)
 
      {
    
       maxheap_insert(left_heap,new_element,&left_heap_size);
   
        
       }
    
   else

       {
          
         
 int right_max = extractMin (right_heap, &right_heap_size);
     
     maxheap_insert(left_heap, right_max, &left_heap_size);
        
  minheap_insert(right_heap, new_element, &right_heap_size);
     
     
       }
     
  new_median = (getMax(left_heap) + getMin(right_heap)) /2;
    
   return new_median;
 
  }
  
  
}


int main ()

{
  
int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
  
int size = 12;

  int current_median=0, next_median;
  
for(int i = 0; i < size; i++)
  
  {
       
 next_median = getMedian(A[i], current_median);
  
      current_median = next_median;
   
     printf("\nThe median after processing %d is %d", A[i],next_median);
   
 }

}