unsigned int count = 0;

void counter()
{
  if (count++ > MAX_COUNT)
    return;
  /* ... */
}