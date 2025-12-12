"""
You are given an integer numberOfUsers representing the total number of users and an array events of size n x 3.

Each events[i] can be either of the following two types:

Message Event: ["MESSAGE", "timestampi", "mentions_stringi"]
This event indicates that a set of users was mentioned in a message at timestampi.
The mentions_stringi string can contain one of the following tokens:
id<number>: where <number> is an integer in range [0,numberOfUsers - 1]. There can be multiple ids separated by a single whitespace and may contain duplicates. This can mention even the offline users.
ALL: mentions all users.
HERE: mentions all online users.
Offline Event: ["OFFLINE", "timestampi", "idi"]
This event indicates that the user idi had become offline at timestampi for 60 time units. The user will automatically be online again at time timestampi + 60.
Return an array mentions where mentions[i] represents the number of mentions the user with id i has across all MESSAGE events.

All users are initially online, and if a user goes offline or comes back online, their status change is processed before handling any message event that occurs at the same timestamp.

Note that a user can be mentioned multiple times in a single message event, and each mention should be counted separately.
***********
Ans:

Just sort them by timestamp maintain online and offline 
then for each query get the timestamp and check how many people have last seen before  60 min 
and remove them from offline 
and make adjustments for the rest simples 
"""

class Solution:
    def countMentions(self, num_u: int, a: List[List[str]]) -> List[int]:
        online, offline = set(), set()
        last_seen = {}
        res = [0] * num_u
        a.sort(key=lambda x: (int(x[1]),-ord(x[0][0])))
        for i in range(num_u):
            online.add(i)
        for msg, time, mntion in a:
            time = int(time)
            for uid, ls in last_seen.items():
                if time >= (ls + 60):
                    offline.discard(uid)
                    online.add(uid)
            if msg == "OFFLINE":
                uid = int(mntion)
                offline.add(uid)
                last_seen[uid] = time        
                online.discard(uid)
            elif msg == "MESSAGE":
                if mntion == "ALL":
                    res = [x + 1 for x in res]
                elif mntion == "HERE":
                    for u in online:
                        res[u]+=1
                else:
                    ids = mntion.split(" ")
                    for s in ids:
                        if s.startswith("id"):
                            uid = int(s[2:])
                            res[uid] += 1
        return res
