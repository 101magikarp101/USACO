print(solved("hello"));

function solved(str) {
    if (str.length % 2 !== 0) {
        str = str.slice(0,str.length/2)+str.slice(str.length/2+1);
    }
    var arr = str.split('');
    arr.sort();
    var result = arr.join('');
    return result;
}