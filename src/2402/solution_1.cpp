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
    vector<bool> occupied(n, false);

    MeetingRoom curr;
    int diff, lookup;
    for(vector<int> m : meetings) {
      // first unoccupy the meeting rooms that will be free_at before this meeting started
      while(!q.empty() && q.top().free_at <= m[0]) {
        occupied[q.top().room_id] = false;
        q.pop();
      }

      // looking up for the unoccupied meeting room with lowest room-id
      for(lookup=0; lookup<n; lookup+=1) {
        if(!occupied[lookup]) {
          q.push(MeetingRoom(m[1], lookup));
          occupied[lookup] = true;
          mcount[lookup] += 1;
          break;
        }
      }

      // there is no unoccupied meeting room at this moment
      // need to delay the current meeting untill the first room got unoccupied from the priority-queue
      if(lookup == n) {
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