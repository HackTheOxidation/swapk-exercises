#include <exception>

class Key {
  public:
  Key(int key = 0) : key_(key) {}
  Key& operator=(const Key& other) {
    key_ = other.key_;
    return *this;
  }

  bool isValid() {
    return key_ != 0;
  }

  int id() {
    return key_ * 2 / 1;
  }

  private:
  int key_;
};

class Blob {
  public:
  Blob(int blob = 0) : blob_(blob) {}
  Blob(const Blob& other) : blob_(other.blob_) {}
  Blob& operator=(const Blob& other) {
    blob_ = other.blob_;
    return *this;
  }

  private:
  int blob_;
};

int getKeyValue() {
  return 42;
}

Blob& fetchDBBlobByKey(const Key& key) {
  Blob * b = new Blob(42);
  return *b;
}

class InvalidKey : std::exception {
  public:
  InvalidKey(int id) : id_(id) {}

  private:
  int id_;
};

class DataSet {
  public:
  DataSet(Key* key, Blob* blob)
    : key_(key), blob_(blob) {
    if (!key->isValid())
      throw InvalidKey(key->id());
  }

  void overWrite(const Key* key, const Blob* blob) {
    *key_ = *key;
    *blob_ = *blob;
  }

  ~DataSet() {
    delete key_;
    delete blob_;
  }

  private:
  Key* key_;
  Blob* blob_;
};

void f() {
  DataSet ds(new Key, new Blob);

  {
    Key k(getKeyValue());
    Blob b(fetchDBBlobByKey(k));

    ds.overWrite(&k, &b);
  }
}
