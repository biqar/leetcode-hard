//
// Created by Islam, Abdullah Al Raqibul on 09/07/22.
//

struct MeetingRoom {
  // note: it'a a trap here!
  // there will be 10^5 meetings with (5 * 10^5) as the start/end time
  // declaring free_at as 32-bit int would overflown
  long long free_at;
  int room_id;

  MeetingRoom() {}
  MeetingRoom(long long free_at, int room_id) : free_at(free_at), room_id(room_id) { }
};

struct CompareMeetingRoom {
  bool operator()(MeetingRoom const& r1, MeetingRoom const& r2) {
    if(r1.free_at == r2.free_at) return r1.room_id > r2.room_id;
    return r1.free_at > r2.free_at;
  }
};

bool compmeetings(vector<int> const& m1, vector<int> const& m2) {
return m1[0] < m2[0];
}

class Solution {
public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    // priority queue will track the occupied rooms with lowest free_at and room-id order
    priority_queue<MeetingRoom, vector<MeetingRoom>, CompareMeetingRoom> q;
    sort(meetings.begin(), meetings.end(), compmeetings);
    vector<int> mcount(n, 0);

    // this set will track the available meeting rooms
    set<int> available;
    for(int i=0; i<n; i+=1) available.insert(i);

    MeetingRoom curr;
    int diff, lookup;
    for(vector<int> m : meetings) {
      // first make the meeting rooms available, that will be free_at before this meeting started
      while(!q.empty() && q.top().free_at <= m[0]) {
        available.insert(q.top().room_id);
        q.pop();
      }

      // looking up for the available meeting room with lowest room-id
      if(available.size()) {
        auto it = available.begin();
        q.push(MeetingRoom(m[1], *it));
        mcount[*it] += 1;
        available.erase(it);
      }
      else {
        // there is no available meeting room at this moment
        // need to delay the current meeting untill the first room got available from the priority-queue
        curr = q.top();
        q.pop();
        diff = m[1] - m[0];
        mcount[curr.room_id] += 1;
        q.push(MeetingRoom(curr.free_at + diff, curr.room_id));
      }
    }

    int mx = *max_element(mcount.begin(), mcount.end());
    for(int i=0; i<n; i+=1) if(mcount[i] == mx) return i;
    return -1;
  }
};