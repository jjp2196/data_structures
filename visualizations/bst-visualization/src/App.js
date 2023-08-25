// src/App.js
import React, { Component } from 'react';
import './App.css';
import BST from './BST';

class App extends Component {
  constructor(props) {
    super(props);

    // Create a sample BST with hardcoded values
    this.state = {
      bstData: [10, 5, 15, 3, 7, 12, 18],
    };
  }

  render() {
    return (
      <div className="App">
        <h1>Binary Search Tree Visualization</h1>
        <BST data={this.state.bstData} />
      </div>
    );
  }
}

export default App;
