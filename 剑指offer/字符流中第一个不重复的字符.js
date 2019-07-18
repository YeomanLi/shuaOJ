//Init module if you need
let map = {}
function Init() {
  // write code here
  map = {}
}

//Insert one char from stringstream
function Insert(ch) {
  // write code here
  // if (map[ch])
  //   map[ch] += 1
  // else
  //   map[ch] = 1
  map[ch] = map[ch] ? map[ch] + 1 : 1
}

//return the first appearence once char in current stringstream
function FirstAppearingOnce() {
  // write code here
  for (let ch in map)
    if (1 === map[ch])
      return ch
  return '#'
}
