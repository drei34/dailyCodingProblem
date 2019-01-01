class Solution {
public:
  map <string, set <string> > g;
  map < pair <string, string>, int> tickets_count; 
    
  bool getItinerary(vector <string> & itinerary, map <pair<string,string>, int> & used_tickets_count) {
        
    /*
        copy(itinerary.begin(),itinerary.end(),ostream_iterator <string>(cout, " "));
        cout << endl;
    */
        
    if(used_tickets_count == tickets_count) {
      return true;
    } else {
      auto city = itinerary.back();
      auto next_cities = g[itinerary.back()];
      for(auto next_city: next_cities) {
	auto p = make_pair(city, next_city);
	if(used_tickets_count[p] < tickets_count[p]) {
	  itinerary.push_back(next_city);
	  used_tickets_count[p] += 1;
	  bool done = getItinerary(itinerary, used_tickets_count);
	  if(done) {
	    return true;
	  }
	  itinerary.pop_back();
	  used_tickets_count[p] -= 1;
	}
      }
    }
    return false;
  }
    
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for(int i = 0; i != tickets.size(); i++) {
      g[tickets[i].first].insert(tickets[i].second);
      tickets_count[tickets[i]] += 1;
    }
                
    vector <string> itinerary;
    map <pair <string, string>, int > used_tickets_count;
        
    itinerary.push_back("JFK");
        
    getItinerary(itinerary, used_tickets_count);
        
    return itinerary;
  }
};
