#include "event.cpp"
#include "game.cpp"

template class Game<int>;
template class Event<int>;

template class Game<float>;
template class Event<float>;

template class Game<double>;
template class Event<double>;

template class Game<long long>;
template class Event<long long>;

template ostream &operator<<(ostream &, const Game<int> &);
template ostream &operator<<(ostream &, const Game<double> &);
template ostream &operator<<(ostream &, const Game<float> &);
template ostream &operator<<(ostream &, const Game<long long> &);
