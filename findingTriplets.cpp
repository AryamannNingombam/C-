
//Objective : Finding a pythagoras triplet 
// in an array and checking if it is possible
// to find one triplet.


bool checkTriplet(int arr[], int n) {

	    //Sorting all the elements
		sort(arr,arr+n);
		//Squaring all the elements
		for (int i{};i<n;i++){
			arr[i] = pow(arr[i],2);
		};
		//Starting from the last point;
		int hypPointer = n-1;
		
		//While the hypotenuse is not the first element. (Won't be possible as the array is sorted);
		while (hypPointer != 1){
			//Initializing the first pointer to 0;
			int firstPointer = 0;
			//Initializing the second pointer one index before the hypotenuse (as the base/height cannot be
			//larger than the hypo)
			int secondPointer = hypPointer - 1;
			//If they collide,break the loop; Pair not found;
			while(firstPointer != secondPointer){
			 
				int height =  arr[firstPointer];
				int base = arr[secondPointer];
					//pair found;
					if ( height+base== arr[hypPointer])return true;

					//If value is more,then a smaller value
					//is needed so we slide one index back
					else if (height+base > arr[hypPointer])secondPointer--;
					//If value is larger,then a larger value
					//is needed so we slide one slide forward;
					else firstPointer++;

				


			};

			//If not found, decrement the hypo and start again.
			 hypPointer--;
			 firstPointer = 0;
			 secondPointer = hypPointer - 1;
		};
		

	    //If no pair is found;
	    return false;
	    
	};
