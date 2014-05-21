function Sandpile(rows, cols) {
  this.rows = rows;
  this.cols = cols;
  this.buf = Module._malloc(rows*cols*32);
  this.fill(0);
}

Sandpile.prototype.fill = function(v) {
  for (var r=0; r<this.rows; r++) {
    for (var c=0; c<this.cols; c++) {
      this.set(r,c,v);
    }
  }
};

Sandpile.prototype.get = function(r,c) {
  var i = r * this.cols + c;
  return Module.getValue(this.buf + 4 * i, 'i64');
};

Sandpile.prototype.set = function(r,c,v) {
  var i = r * this.cols + c;
  Module.setValue(this.buf + 4 * i, v, 'i64');
};

Sandpile.prototype.setIdentity = function() {
  Module._get_identity(this.rows, this.cols, this.buf);
};

Sandpile.prototype.update = function() {
  Module._update_sandpile(this.rows, this.cols, this.buf);
};

Sandpile.prototype.print = function() {
  Module._print_sandpile(this.rows, this.cols, this.buf);
};

Sandpile.prototype.free = function() {
  Module._free(this.buf);
};

