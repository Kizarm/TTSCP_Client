#ifndef TEMPERATURE_H
#define TEMPERATURE_H

class Temperature {
  int correction0;
  int correction1;
  int average;
  public:
    explicit Temperature() noexcept;
    int meassure ();
};

#endif // TEMPERATURE_H
