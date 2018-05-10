#ifndef VECTOR_2D_HPP
#define VECTOR_2D_HPP

class Vector2D {
  private:
    int x = 0;
    int y = 0;

  public:
    int getX();
    void setX(int inputX);
    int getY();
    void setY(int inputY);
};
#endif // VECTOR_2D_HPP