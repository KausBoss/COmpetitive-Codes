template<typename T>
class graph{
	unordered_map<T, list<T>> m;
public:
	void addEdge(T a, T b, bool bidir=true){
		m[a].pb(b);
		if(bidir){
			m[b].pb(a);
		}
	}
};