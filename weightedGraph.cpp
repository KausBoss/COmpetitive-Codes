template<typename T>
class graph{
	unordered_map<T, list<pair<T, ll>>> m;
public:
	void AddEdge(T a, T b, bool bidir=true, ll cost){
		m[a].pb(mp(b, cost));
		if(bidir){
			m[b].pb(mp(a, cost));
		}
	}
};