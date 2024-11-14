#ifndef COOKIE_H
#define COOKIE_H

double max_dv(int n, int* array) {

	// You should check the value is valid.
	if(n <= 0) return -1;
	for(int i = 0; i < n; i++){
		int dv = array[i];
		if(dv < 0 || dv > 100){
			return -1;
		}
	}

	// Total the dv on every odd position.
	int to = 0;
	for(int i = 1; i < n; i += 2){
		to += array[i];
	}
	// Total the dv on every even position
	int te = 0;
	for(int i = 0; i < n; i += 2){
		te += array[i];
	}
	// Return maximum between to and te.
	return to >= te ? to : te;

} // end of cookie

#endif // end of include guard: COOKIE_H
//here is a small edition