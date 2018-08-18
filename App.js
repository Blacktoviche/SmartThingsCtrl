/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

import React, { Component } from 'react';
import {
  Platform,
  StyleSheet,
  View, Alert
} from 'react-native';

import {
  Container, Header, Content, List, ListItem,
  Text, Icon, Left, Body, Right, Switch, Title, Spinner, Button
} from 'native-base';

const fanPin = 0;
const kitchenPin = 1;
const bedroomPin = 2;
const salonPin = 3;
const bathroomPin = 4;

const API_IP = "http://192.168.17.102";

export default class App extends Component {

  constructor() {
    super();
    this.state = {
      fan: false,
      kitchen: false,
      bedroom: false,
      salon: false,
      bathroom: false,
      bodyState: false,
    }
  }

  toggleFan = (value) => {
    let intValue = value ? 1 : 0;
    fetch(`${API_IP}/led/${fanPin}/${intValue}`, {
      method: 'GET'
    }).then((response) => {
      if (response.status === 200) {
        this.setState({ fan: value });
      }
    }).catch((error) => {
      Alert.alert("Error: " + error);
    });
  }

  toggleKitchen = (value) => {
    let intValue = value ? 1 : 0;
    fetch(`${API_IP}/led/${kitchenPin}/${intValue}`, {
      method: 'GET'
    }).then((response) => {
      if (response.status === 200) {
        this.setState({ kitchen: value });
      }
    }).catch((error) => {
      Alert.alert("Error: " + error);
    });
  }

  toggleBedroom = (value) => {
    let intValue = value ? 1 : 0;
    fetch(`${API_IP}/led/${bedroomPin}/${intValue}`, {
      method: 'GET'
    }).then((response) => {
      if (response.status === 200) {
        this.setState({ bedroom: value });
      }
    }).catch((error) => {
      Alert.alert("Error: " + error);
    });
  }

  toggleSalon = (value) => {
    let intValue = value ? 1 : 0;
    fetch(`${API_IP}/led/${salonPin}/${intValue}`, {
      method: 'GET'
    }).then((response) => {
      if (response.status === 200) {
        this.setState({ salon: value });
      }
    }).catch((error) => {
      Alert.alert("Error: " + error);
    });
  }

  toggleBathroom = (value) => {
    let intValue = value ? 1 : 0;
    fetch(`${API_IP}/led/${bathroomPin}/${intValue}`, {
      method: 'GET'
    }).then((response) => {
      if (response.status === 200) {
        this.setState({ bathroom: value });
      }
    }).catch((error) => {
      Alert.alert("Error: " + error);
    });
  }

  componentDidMount() {
    this.readPinsStatus();
  }

  readPinsStatus() {
    this.setState({ bodyState: false });
    fetch(`${API_IP}/led/read/`, {
      method: 'GET'
    }).then((response) => {
      if (response.status === 200) {
        response
          .json()
          .then((data) => {
            console.log("data: ", data)
            this.setState({ fan: data.D0 == 0 ? false : true });
            this.setState({ kitchen: data.D1 == 0 ? false : true });
            this.setState({ bedroom: data.D2 == 0 ? false : true });
            this.setState({ salon: data.D3 == 0 ? false : true });
            this.setState({ bathroom: data.D4 == 0 ? false : true });
            this.setState({ bodyState: true });
          })
      }
    }).catch((error) => {
      Alert.alert("Error: " + error);
    });
  }
  renderBody() {
    if (this.state.bodyState) {
      return (

        <Content>
          <ListItem icon>
            <Left>
              <Button style={{ backgroundColor: "#FF9501" }}>
                <Icon active name="plane" />
              </Button>
            </Left>
            <Body>
              <Text>Fan</Text>
            </Body>
            <Right>
              <Switch onValueChange={(value) => this.toggleFan(value)}
                value={this.state.fan} />
            </Right>
          </ListItem>
          <ListItem icon>
            <Left>
              <Button style={{ backgroundColor: "#FF9501" }}>
                <Icon active name="plane" />
              </Button>
            </Left>
            <Body>
              <Text>Kitchen Led</Text>
            </Body>
            <Right>
              <Switch onValueChange={(value) => this.toggleKitchen(value)}
                value={this.state.kitchen} />
            </Right>
          </ListItem>
          <ListItem icon>
            <Left>
              <Button style={{ backgroundColor: "#FF9501" }}>
                <Icon active name="plane" />
              </Button>
            </Left>
            <Body>
              <Text>Salon Led</Text>
            </Body>
            <Right>
              <Switch onValueChange={(value) => this.toggleSalon(value)}
                value={this.state.salon} />
            </Right>
          </ListItem>
          <ListItem icon>
            <Left>
              <Button style={{ backgroundColor: "#FF9501" }}>
                <Icon active name="plane" />
              </Button>
            </Left>
            <Body>
              <Text>Bedroom Led</Text>
            </Body>
            <Right>
              <Switch onValueChange={(value) => this.toggleBedroom(value)}
                value={this.state.bedroom} />
            </Right>
          </ListItem>
          <ListItem icon>
            <Left>
              <Button style={{ backgroundColor: "#FF9501" }}>
                <Icon active name="plane" />
              </Button>
            </Left>
            <Body>
              <Text>Bathroom Led</Text>
            </Body>
            <Right>
              <Switch onValueChange={(value) => this.toggleBathroom(value)}
                value={this.state.bathroom} />
            </Right>
          </ListItem>
          <Button full danger onPress={() => this.readPinsStatus()}><Text>Referesh</Text></Button>
        </Content>

      );
    } else {
      return (
        <Content>
          <Spinner color='red' />
          <Button full danger onPress={() => this.readPinsStatus()}><Text>Referesh</Text></Button>
        </Content>
      );
    }
  }
  render() {
    return (
      <Container>
        <Header>
          <Title>Smart Things Control</Title>
        </Header>
        {this.renderBody()}
      </Container>);
  }
}