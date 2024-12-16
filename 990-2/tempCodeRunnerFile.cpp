;
        // int cnt = N;
        // while (!s.empty()) {
        //     int tar = s.begin()->x;
        //     s.erase(s.begin());
        //     vt<state> v;
        //     while (!dq.empty() && dq.front().v > tar) {
        //         v.pb({dq.front().s,dq.front().v+1,dq.front().i});
        //         dq.pop_front();
        //     }
        //     auto cur = dq.front();
        //     dq.pop_front();
        //     if (sz(cur.s) == 1) {
        //         ans.pb(*cur.s.begin() + cur.v);
        //     } else {
        //         cur.s.erase(cur.s.begin());
        //         dq.push_front(cur);
        //         s.insert({cur.v,cur.i});
        //     }
        //     if (v.empty()) continue;
        //     if (sz(v)==1) {
        //         dq.push_back({v[0].s,v[0].v,cnt});
        //         s.insert({v[0].v,cnt++});
        //         continue;
        //     }
        //     sort(all(v),[](state a, state b) {
        //         return sz(a.s) > sz(b.s);
        //     });
        //     rep(i,1,sz(v)) {
        //         each(j,v[i].s) {
        //             v[0].s.insert(j+v[i].v-v[0].v);
        //         }
        //     }
        //     dq.push_back({v[0].s,v[0].v,cnt});
        //     s.insert({v[0].v,cnt++});
        // }