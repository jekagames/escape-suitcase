// Konami code in keycodes (ENTER substituted for START)
// UP UP DOWN DOWN LEFT RIGHT LEFT RIGHT A B ENTER
let konami = [38, 38, 40, 40, 37, 39, 37, 39, 65, 66, 13];
// Which key (in the array) are we waiting to see the user type next?
// To begin with it's the first (0th) one
let currentKey = 0;

// We need to listen to keydown events on the page to detect when a key is pressed
document.addEventListener('keydown', keyPressed);

// This is the function called when a key is pressed
// e contains information about that event
function keyPressed(e) {
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
      document.removeEventListener('keydown', keyPressed);
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