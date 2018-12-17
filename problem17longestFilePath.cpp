class Solution {
public:
    
  int lengthLongestPath(string input) {
    int longest_path = 0;
    int current_path = 0;
        
    stack <string> f;
    int i = 0;
    while(i < input.size()) {
      int j = i;
      int n_t = 0;
      if(input[j] == '\n') {
	// Skip the new line.
	j += 1;
	// Go as many tabs deep as needed.
	while(input[j] == '\t') {
	  j += 1;
	  n_t += 1;
	}
      }
            
      string current;
      while(input[j] != '\n' && j < input.size()) {
	current += input[j];
	j += 1;
      }
                                
      while(f.size() !=  n_t && !f.empty()) {
	current_path -= f.top().size();
	f.pop();
      }
                
      // A file.
      if(current.find(".") != string::npos) {
	longest_path = max(longest_path, (int)current.size() + current_path + (int)f.size());
      } 
      // A directory.
      else {
	f.push(current);
	current_path += current.size();
      }
                
      i = j;
                
    }
        
    return longest_path;
  }
};
