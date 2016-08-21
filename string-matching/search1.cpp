#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Problem is a generic class that represents a problem
contains methods:
	actions(state) // returns a vector containing possible actions from this state
	performAction(action, state) // takes in an action and a state and returns a new state

	cost(action,state) //  returns the cost of performing this action on this state





*/
	
class 8PuzzleProblem{
public:

	typedef move Action;
	typedef Board State;

	vector<Action> actions(State s);
	State performAction(Action a, State s)
	{

	}
	int cost(State s, Action a) {return 1;}

	vector<Action> actions(State currState)
	{
			
		pair<int,int> coords = currState.posOfZero();
		int x = coords.first,y = coords.second;
		vector<Action> valid;
		if (x != )
	}

	bool goalTest(Board b)
	{
		vector<int> k = b.a;
		for (int i =0; i < k.size(); ++k)
			if (k[i] != i)
				return false;
		return true;
	}




private:
	static const int size = 3;
	struct move{
		int delX,delY;
		move(int a,int b): delX(a),delY(b){}


	};

	struct Board
	{
		vector<int> a(9);

		ostream& operator<<()
		{
			for (int j = 0; j < size; ++j){
				for (int i = 0; i < size; ++i)
					cout << a[i + 3*j];
			cout << '\n';
			}
		}


		pair<int,int> posOfZero()
		{
			for (int j = 0; j < size; ++j)
				for (int i = 0; i < size; ++i)
					if (a[i + 3*j] == 0)
						return make_pair(i,j);
		}

		bool operator==(const Board& rhs)
		{
			return a == rhs.a;
		}



	};


	State initState;

}

template <typename Problem>
class Node{
public:
	typedef Problem::Action action;
	typedef Problem::State state;
	Node(Node* parent, Problem p, int cost): p(p), parent(parent), cost(cost)

	bool operator==(const Node& rhs){ return curr == rhs.curr;}



	Vector<Node*> successors()
	{
		Vector<State> a = p.genSuc(curr);
		Vector<Node*> b;
		b.reserve(a.size());
		for (size_t i = 0; i < a.size(); ++i)
			b[i] = new Node(this, p, cost + p.cost())
	}

private:
	Problem p;
	State curr;
	Node* parent;
	int cost;

	Node* genNode(Node* parent)
	{
		return new Node(parent, p);
	}

};




