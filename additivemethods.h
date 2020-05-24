namespace AdditiveMethods {
template <typename T>
static bool contains(T element, const T arr[], int length) {
  for (int i = 0; i < length; i++)
    if (arr[i] == element)
      return true;
  return false;
}
} // namespace AdditiveMethods
