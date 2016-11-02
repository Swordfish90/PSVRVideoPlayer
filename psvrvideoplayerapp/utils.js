
.pragma library

function nearestPow2(aSize){
    return Math.pow(2, Math.round(Math.log(aSize) / Math.log(2)));
}
