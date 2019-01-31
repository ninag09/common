class graph{
    public:
        graph(int V){
            this->V = V;
            aList = new std::list<int>[V];
        } 

        void addEdge(int v, int w){
            aList[v].push_back(w);
        }

        int V;
        std::list<int>* aList;
};
