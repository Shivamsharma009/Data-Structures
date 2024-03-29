/* Java program to group multiple occurrences of individual array elements */
import java.util.HashMap; 

class MultipleOccurence 
{ 
	// A hashing based method to group all occurrences of individual elements 
	static void orderedGroup(int arr[]) 
	{ 
		// Creates an empty hashmap 
		HashMap<Integer, Integer> hM = new HashMap<Integer, Integer>(); 

		// Traverse the array elements, and store count for every element 
		// in HashMap 
		for (int i=0; i<arr.length; i++) 
		{ 
		// Check if element is already in HashMap 
		Integer prevCount = hM.get(arr[i]); 
		if (prevCount == null) 
				prevCount = 0; 
			
		// Increment count of element element in HashMap 
		hM.put(arr[i], prevCount + 1); 
		} 

		// Traverse array again 
		for (int i=0; i<arr.length; i++) 
		{ 
			// Check if this is first occurrence 
			Integer count = hM.get(arr[i]);	 
			if (count != null) 
			{ 
				// If yes, then print the element 'count' times 
				for (int j=0; j<count; j++) 
				System.out.print(arr[i] + " "); 
				
				// And remove the element from HashMap. 
				hM.remove(arr[i]); 
			} 
		} 
	} 

	// Driver method to test above method 
	public static void main (String[] args) 
	{ 
		int arr[] = {10, 5, 3, 10, 10, 4, 1, 3}; 
		orderedGroup(arr); 
	} 
} 
