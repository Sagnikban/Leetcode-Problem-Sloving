class Solution {
public:
     //comparartor function to comare if the lastday of a course
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }    
    int scheduleCourse(vector<vector<int>> &courses){
        //soring according to lastday in increasing order.
        sort(courses.begin(), courses.end(), comp);
        
        //priority queue to store duration of couses
        priority_queue<int> maxD;

        int time = 0; // time to store the total time taken
        for (int i=0;i<courses.size();i++){
            
            //if total time taken including this course is lesser than or equak to the last day then add couse to queue and add the time to total time
            if (time + courses[i][0] <= courses[i][1]){
                time += courses[i][0];
                maxD.push(courses[i][0]);
            }
            
            //else if there are element in priority queue then check if current course is shorter than the max previous couse then just replace that with current
            else if (!maxD.empty() && maxD.top() >= courses[i][0]){
                time = time - maxD.top() + courses[i][0]; //replacing max previous course with current in toytal time
                maxD.pop();                           //taking out max previous
                maxD.push(courses[i][0]);                 //adding current course
            }
        }
        
        //as queue only contains the courses taken so size of queue is the number of courses.
        return maxD.size();
    }
};