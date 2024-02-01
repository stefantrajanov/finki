// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
export const environment  = {
  apiKey: "AIzaSyAUcQgdr3jgkaf-oZgpMVtCzzRpwlvLZ7Q",
  authDomain: "ng-skillpix.firebaseapp.com",
  databaseURL: "https://ng-skillpix-default-rtdb.europe-west1.firebasedatabase.app",
  projectId: "ng-skillpix",
  storageBucket: "ng-skillpix.appspot.com",
  messagingSenderId: "746024340771",
  appId: "1:746024340771:web:693619d6166fbb25369096",
  measurementId: "G-4WFHL1G23E"
};

// Initialize Firebase
const app = initializeApp(environment);
const analytics = getAnalytics(app);

