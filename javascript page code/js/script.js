// Konami code in keycodes (ENTER substituted for START)
// UP UP DOWN DOWN LEFT RIGHT LEFT RIGHT A B ENTER
//let konami = [38, 38, 40, 40, 37, 39, 37, 39, 65, 66, 13];

//W A S D F -- might need to be reordered to make it less obvious once things are wired up
let konami = [87, 65, 83, 68, 70];
// Which key (in the array) are we waiting to see the user type next?
// To begin with it's the first (0th) one
let currentKey = 0;

// We need to listen to keyup events on the page to detect when a key is pressed & released, because Makey Makey can trigger multiple keypresses together by accident
document.addEventListener('keyup', keyUp);

setTimeout(function(){
   window.location.reload(1);
}, 180000);
//180000 = 3 minutes
// This is the function called when a key is pressed
// e contains information about that event
function keyUp(e) {
  // Check if the keycode of the key pressed matches the one we're currently
  // waiting for in the konami code
  if (e.keyCode === konami[currentKey]) {
    // If it matches we can wait for the next one by advanced the currentKey by one
    currentKey++;
    // For debugging, let's notify ourselves how many we have right in a row
    console.log(currentKey + ' correct.');
    // Check if the number of correct keys matches the length of the konami code (in the array)
    if (currentKey === konami.length) {
      // If so, then let's display the secret message div by setting its display style to block
      document.getElementById('secret-message').style.display = 'block';
      // And let's hide the non-secret message by setting its display style to none
      document.getElementById('not-secret-message').style.display = 'none';
      // And let's stop listening to the keyboard to avoid checking the code anymore
      document.removeEventListener('keyup', keyUp);
    }
  }
  else {
    // If we're here, they typed a key that wasn't correct for the code
    // So let's remind ourselves this happened for debugging
    console.log("Incorrect key. Resetting.");
    // And let's reset the code back to the beginning
    currentKey = 0;
  }

}