#include <vector>
#include <iostream>

using namespace std;

class MyCalendar{
    public:
    
        vector<pair<int, int>> events;

        MyCalendar(){
        }

        int binarySearch(int start){

            if(events.size() <= 1)
                return 0;
            
            if(events[0].first > start)
                return 0;
            
            if(events[events.size()-1].first < start)
                return events.size() - 1;

            int left = 0;
            int right = events.size() - 1;
            int mid = 0;

            while(left < right){
                
                mid = (left + right) / 2;

                if(events[left].first == start)
                    return left;
                if(events[right].first == start)
                    return right;
                if(events[mid].first == start)
                    return mid;

                if(events[mid].first > start){
                    if(events[mid-1].first <= start)
                        return mid-1;
                    else
                        right = mid - 1;
                }
                else{
                    if(events[mid+1].first >= start)
                        return mid;
                    else
                        left = mid + 1;
                }
            }
            
            return left;
        }

        bool book(int start, int end){

            if(events.size() == 0){
                events.push_back({start, end});
                return true;
            }

            pair<int, int> p = {start, end};
            int index = binarySearch(start);

            cout << "index: " << index << endl;
            cout << "current list: " << endl;
            for(auto item: events){
                cout << item.first << " " << item.second << endl;
            }
            cout << "Completed" << endl;


            if(index == 0){
                if(events[0].first >= end){
                    events.insert(events.begin(), p);
                    return true;
                }
                else if(events[0].second <= start)
                {
                    if(events.size() == 1){
                        events.push_back(p);
                        return true;
                    }
                    else if(events[1].first >= end){
                        events.insert(events.begin() + 1, p);
                        return true;
                    }
                    else
                        return false;

                }
                else{
                    return false;
                }
            }

            if(index == events.size() - 1){
                if(events[events.size()-1].second <= start){
                    events.push_back(p);
                    return true;
                }
                else
                    return false;
            }

            if(events[index].second <= start){
                if(events[index+1].first >= end){
                    events.insert(events.begin() + index + 1, p);
                    return true;
                }
                else
                    return false;
            }
            else
                return false;

        }
};

int main(){

    MyCalendar myCalendar = MyCalendar();
    bool res = myCalendar.book(10, 20);
    cout << res << endl;
    res = myCalendar.book(15, 25);
    cout << res << endl;
    res = myCalendar.book(20, 30);
    cout << res << endl;

    return 0;
}